# 一 Vue基础

## 1.1 第一个vue程序

```html
<head>
    <meta charset="UTF-8">
    <script src="../js/vue.js"></script>
    <script>
        Vue.config.productionTip = false;
    </script>
    <title>Document</title>
</head>
<body>
    <div id="root">
        {{message}}
    </div>
    <script>
        new Vue({
            el:'#root',
            data:{
                message:"Hello Vue!"
            }
        })
    </script>
</body>
```

## 1.2 el挂载点

- Vue实例的作用范围是什么?
  - vue会管理el选项命中的元素及其内部的后代元素

- 是否可以其他选择器
  - 可以使用其他的选择器，但是建议i使用id选择器
- 是否可以设置其他dom元素
  - 基本都可以，但是有一些不行[body,html]



## 1.3 data数据对象

data中的可以直接在 容器中使用，任何类型都可以



# 二 本地应用

- v-text 设置标签的文本值

  ```html
  <div id="app">
      <h2 v-text="message"></h2>
  </div>
  <script>
      new Vue({
          el:'#app',
          data:{
              message:"乃荣程序员!"
          }
      })
  </script>
  ```

  缺点：会直接替换所有内部文字，还是建议插值法

- v-html

  ```htlm
  和v-text 比较像，但是它能解析html标签
  ```

- v-on

  ```html
  为元素绑定是事件
  onclick,onmouseenter
  
  <input type="button" value="事件绑定" v-on:click="f">
  <p  v-on:monseenter="f">aaa</p>
  <input type="button" value="事件绑定" v-on:dblclick="f">
  
  指令可以简写为@
  <input type="button" value="换菜！" @click="changeFood">
  
  v-on也可以传自定义参数
  	写法和调用函数传参十分类似
  @click = dolt(p1,p2,p3...
  )
  
  
  键盘事件 @keyup和@keydown
  @keyup.enter="f" 表示回车
  还有更多常见修饰符可以去百度
  ```

- 计数器

   ```html
  <div id="app">
      <button @click="pop">-</button>
  <span>{{number}}</span>
  <button @click="add">+</button>
  </div>
  <script>
      new Vue({
      el:'#app',
      data:{
          number:1
      },
      methods: {
          add(){
              let number = this.number;
  
              if (number < 10){
                  this.number++
                  return
  
              }
              alert('您已经到最大值了')
  
          },
          pop(){
              let number = this.number;
              if (number > 0){
                  this.number--
                  return
              }
              alert('您已经到最小值了')
          }
      },
  })
  </script>
   ```

  

- v-show

  ```html
  根据表达值的真假，切换元素的显示和隐藏
  
  <div id="app">
      <button @click = f>开关</button>
      <div v-show="flag">你发现了隐藏数据。。。</div>
  </div>
  <script>
      new Vue({
          el:'#app',
          data:{
              flag:false
          },
          methods: {
              f(){
                  this.flag = !this.flag
              }
          }
      })
  </script>
  ```

- v-if  和v-show基本一样，但是if是真正的消失这个标签，而show不是只是通过css隐藏，所以if更好更安全

  ```html
  根据表达值的真假，切换元素的显示和隐藏(操作dom元素)
  <div id="app">
      <button @click="tog">切换</button>
      <p v-if="flag">我是一个p标签</p>
  
  </div>
  <script>
      new Vue({
          el:'#app',
          data:{
              flag:false
          },
          methods: {
              tog(){
                  this.flag = !this.flag
              }
          }
      })
  </script>
  
  简单写法
  <div id="app">
      <button @click="flag = !flag">切换</button>
      <p v-if="flag">我是一个p标签</p>
  
  </div>
  <script>
      new Vue({
          el:'#app',
          data:{
              flag:false
          },
      })
  </script>
  ```

- v-bind

  ```html
  设置元素的属性
  语法  v-bind:属性名 = 值
  
  
  <div id="app">
      <img :src="imgSrc">
  </div>
  ```

- v-for

  ```html
  根据数据生产列表结构
  
  数组经常和f-vor结合使用
  语法是(item,index) in 数据
  item和index可以结合其他指令一起使用
  
  <li v-for="i in arr" :title="i">
      {{i}}
  </li>
  <li v-for="i,j in objArr" :title="i.name">
      {{i.name}}{{j}}
  </li>
  ```

- v-model

  ```html
  获取和设置表单元素的值（双向数据绑定）
  绑定的数据会和表单元素值相关联
  
  <div id="app">
      <input type="text" v-model="message">
  </div>
  <script>
      let vm = new Vue({
          el:'#app',
          data:{
              message:'乃荣'
          }
      })
  </script>
  ```

  

# 三 网络应用

Vue结合网络数据开发应用

## 3.1 axios

- axios 必须先导入才可以使用
- 使用get或post方法即可发送对应的请求
- then方法中的回调函数会在请求成功或失败时触发
- 通过回调函数的形参可以获取响应内容，或错误信息

```html
<script src="https://unpkg.com/axios/dist/axios.min.js"></script>
```

```js
axios.get(地址?key=value&key2=vaule2).then(function(response){},function(err){})

axios.post(地址,参数对象).then(function(response){},function(err){})

document.querySelector('.get').onclick = function(){
    axios.get("https://autumnfish.cn/api/joke/list1234?num=3")
        .then(function(response){
        console.log(response);
    },function(err){
        console.log(err)
    })
}


document.querySelector('.post').onclick = function(){
    axios.post("https://autumnfish.cn/api/user/reg",{username:"乃荣"})
        .then(function(response){
        console.log(response);
    },function(err){
        console.log(err);
    })
}
```

## 3.2 axios+vue

axios配合vue使用

- axios回调函数中的this已经改变，无法访问到data中数据
- 把this保存起来，回调函数中直接使用保存的this即可
- 和本地应用的最大区别就是改变了数据来源

 ```html
<div id="app">
    <input type="button" value="获取笑话" @click="getJoke">
    <p>{{joke}}</p>
</div>
<script>
    let vm = new Vue({
        el:'#app',
        data:{
            joke:'一个笑话'
        },
        methods: {
            getJoke(){
                let _this = this;
                axios.get("https://autumnfish.cn/api/joke")
                    .then(function(response){
                    _this.joke = response.data
                },function(err){
                    console.log(err);
                })
            }
        },
    })
</script>
 ```















































