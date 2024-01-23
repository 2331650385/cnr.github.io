class Person(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age
    # __gt__ 会在对象做大于比较的时候调用，该方法的返回值将会作为比较的结果
    # 他需要两个参数，一个self表示当前对象，other表示和当前对象比较的对象
    # self > other
    def __gt__(self, other):
        return self.age > other.age

# 创建两个Person类的实例
p1 = Person('孙悟空', 38)
p2 = Person('猪八戒', 28)

print(p2 > p1)


with open("./a.txt" ,'r',encoding="utf-8",newline="") as f:
    f.seek(2,0)
    print(f.read())
    f.seek(0)
    print(f.read())
    print(f.tell())