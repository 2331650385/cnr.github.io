var vm = new Vue({
    el:'#player',
    data:{
        query:'',
        musicList:[],
        musicUrl:"",
        musicCover:"",
        hotComments:[],
        isPlaying:false
    },
    methods: {

        // 搜索歌曲
        searchMusic(){
            var _this = this;
            axios.get('https://autumnfish.cn/search?keywords='+this.query)
            .then(function(response){
                _this.musicList = response.data.result.songs;
                console.log(_this.musicList);
            },function(err){
                console.log(err);
            })
        },

        //根据歌曲id获取歌曲
        playMusic(musicId){
            let _this = this;
            axios.get("https://autumnfish.cn/song/url?id="+musicId)
            .then(function(response){
                _this.musicUrl = response.data.data[0].url;
            },function(err){
                console.log(err);
            })

            //歌曲详情获取
            axios.get('https://autumnfish.cn/song/detail?ids='+musicId)
            .then(function(response){
                _this.musicCover =response.data.songs[0].al.picUrl;
            },function(err){
                console.log(err);
            })
            //歌曲评论获取
            axios.get("https://autumnfish.cn/comment/hot?type=0&id="+musicId)
            .then(function(responce){
                _this.hotComments = responce.data.hotComments;
                console.log(_this.hotComments);
            },function(err){
                console.log(err);
            })


        },
        play(){
            this.isPlaying = true
        },
        pause(){
            this.isPlaying = false
        }

        
        
    },
})