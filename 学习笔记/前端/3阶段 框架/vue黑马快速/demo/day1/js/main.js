var vm = new Vue({
    
    el:'#app',
    data:{
        city:'',
        weatherList:[]
    },
    methods: {
        searchWeater(){
            let _this = this;
            axios.get('http://wthrcdn.etouch.cn/weather_mini?city='+this.city)
            .then(function(response){
                let arr = response.data.data.forecast;
                _this.weatherList = arr;
                console.log(arr);
            }).catch(function(err){
                console.log(err);
            })
        },
        show_city(city){
            this.city = city;
            this.searchWeater()
        }
    },
})