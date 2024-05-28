import requests
from concurrent.futures import ThreadPoolExecutor
from lxml import etree
import re
import time



def get_items():
    """
    创建一个空的字典模板，用于存储每个文章的信息
    """
    item = {
        'identifier': None,  # 索引号
        'publisher': None,  # 发布机构
        'display_publish_time': None,  # 发布日期
        'title': None,  # 政策标题
        'content': None,  # 政策内容
        'attachment': None,  # 附件URL
    }
    return item

def start_open():
    """
    打开文件并写入CSV头
    """
    f = open("a.csv", "w", encoding='utf-8', newline="")
    f.write("索引号,发布机构,发布日期,政策标题,政策内容,附件URL\n")
    return f

def get_url_source(start_date, end_date, page, f):
    """
    处理异步Json数据，抓取每一页的文章列表，并筛选符合日期范围的文章
    :param start_date: 开始时间
    :param end_date: 结束时间
    :param page: 页码
    :param f: 文件操作句柄
    """
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 Safari/537.36'
    }
    url = f'https://www.gd.gov.cn/gkmlpt/api/all/5?page={page}&sid=2'
    res = requests.get(url=url, headers=headers)
    json_data = res.json()  # 获取json文件
    articles_list = json_data['articles']
    for articles in articles_list:
        item = get_items()
        identifier = articles.get('identifier')  # 索引号
        publisher = articles.get('publisher')  # 发布机构
        display_publish_time = articles.get('display_publish_time')  # 发布日期
        display_publish_time = time.strftime("%Y-%m-%d", time.localtime(display_publish_time))
        title = articles.get('title')  # 政策标题
        post_url = articles.get('post_url')  # post_url
        than_date = display_publish_time.split(" ")[0].replace("-", "")
        if int(end_date) >= int(than_date) >= int(start_date):
            item['identifier'] = identifier
            item['publisher'] = publisher
            item['display_publish_time'] = display_publish_time
            item['title'] = title
            parse_html(post_url, item, f)

def parse_html(post_url, item, f):
    """
    解析每个文章的详细内容并写入文件
    :param post_url: 文章的URL
    :param item: 文章信息字典
    :param f: 文件操作句柄
    """
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/125.0.0.0 Safari/537.36'
    }
    try:
        res2 = requests.get(url=post_url, headers=headers)
        text = res2.content.decode()
        tree = etree.HTML(text)
        content_tree = tree.xpath(r'/html/body//div[@wzades="正文" and @class="zw"]')[0]
        content = "".join(content_tree.xpath(r'.//text()')).strip()
        content = re.sub(r"\u3000", r"", content)  # 替换全角空格
        attachment = "".join(content_tree.xpath('.//p[@noextractcontent]/a/@href'))
        item['content'] = content
        item['attachment'] = attachment
        identifier = item['identifier']
        publisher = item['publisher']
        display_publish_time = item['display_publish_time']
        title = item['title']
        # 将文章信息写入CSV文件
        f.write(f"{identifier},{publisher},{display_publish_time},{title},{content},{attachment}\n")
    except Exception as e:
        print(e)

def fetch_all(start_date, end_date, f):
    """
    使用多线程并发抓取所有页面的数据
    :param start_date: 开始时间
    :param end_date: 结束时间
    :param f: 文件操作句柄
    """
    with ThreadPoolExecutor(max_workers=10) as executor:
        futures = []
        for i in range(1, 11):  # 假设有3页需要抓取
            futures.append(executor.submit(get_url_source, start_date, end_date, i, f))
        for future in futures:
            future.result()  # 等待所有线程完成

if __name__ == '__main__':
    t = time.time()
    f = start_open()
    start_date, end_date = ["20240501", "20240527"]

    fetch_all(start_date, end_date, f)

    f.close()
    print(f"执行了{time.time()-t}秒")