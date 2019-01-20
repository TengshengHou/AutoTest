var hts_janCodeBuf="";
var hts_LastjanCode="";
var queue =new Queue();
var apiHost="http://localhost:8080/";
var scriptId="";
//http://localhost:8080/api/ScriptDetails/CreateLuaAsync?guid=AB16641E-15C9-47C7-DB25-08D67ECA024A
$(function () {
  
    $(document).on("click", function (e) {
        var x = e.originalEvent.x || e.originalEvent.layerX || 0;
        var y = e.originalEvent.y || e.originalEvent.layerY || 0;  
        queue.enqueue({context:x+"|"+y,type:"click"});
    })
   
    document.addEventListener("keypress", function(e){
        htsJanCodeJoin(e);
    })
    var t1 = window.setInterval(SendService,1000); 

    var scriptData= { S_Name:"Test",S_Desc:"测试脚本",S_Lable:"text"} ;
    $.ajax({
        type: "Post",
        dataType:"json",
        //url: "http://localhost:8080/api/script?a=" + new Date().getTime(),    //获取数据的ajax请求地址
        url: apiHost +"api/script",    //获取数据的ajax请求地址
        data: scriptData,
        success: function (data) {
            console.log("data"+data);
            scriptId=data;
        }
    });
});

//拼接JanCode
function htsJanCodeJoin(e)
{
    if (e.which != 13) {
        hts_janCodeBuf+=e.key;
    }else
    {
        hts_LastjanCode=hts_janCodeBuf;
        htsJanCodeCreatedEvent(e,hts_janCodeBuf);
        hts_janCodeBuf="";
    }
}
//创建完成JanCode后执行
function htsJanCodeCreatedEvent(e,janCode)
{
       queue.enqueue( queue.enqueue({context:janCode,type:"code"}));
}

/*--------------Queue类的定义和测试代码----------------*/
function Queue(){
    this.dataStore = [];
    this.enqueue = enqueue;
    this.dequeue = dequeue;
    this.front = front;
    this.back = back;
    this.toString = toString;
    this.empty = empty;
}

//入队，就是在数组的末尾添加一个元素
function enqueue(element){
this.dataStore.push(element);
}
//出队，就是删除数组的第一个元素
function dequeue(){
return this.dataStore.shift();
}
//取出数组的第一个元素
function front(){
return this.dataStore[0];
}
//取出数组的最后一个元素
function back(){
return this.dataStore[this.dataStore.length-1];
}

function toString(){
var retStr = "";
for (var i=0; i<this.dataStore.length; ++i) {
    retStr += this.dataStore[i] + "&nbsp;"
}
return retStr;
}
//判断数组是否为空
function empty(){
if(this.dataStore.length == 0){
    return true;
}else{
    return false;
}    
}
//返回数组中元素的个数
function count(){
return this.dataStore.length;
}


function SendService()
{
    var obj=queue.dequeue();
    if(obj){ 
        $.ajax({
            type: "Post",
            dataType:"json",
            url: apiHost +"api/ScriptDetails",    //获取数据的ajax请求地址
            data: {SD_Script_ID:scriptId,SD_Content:obj.context,SD_EventType:obj.type},
            success: function (data) {
            }
        });
    console.log("SendService"+obj)
    ; 
}   
} 