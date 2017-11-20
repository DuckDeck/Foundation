Array.prototype.shellSort = function(sortMethod){
    if(this.length <= 1){
        return
    }
    let i = 0,j=0,tmp=0
    let increment = this.length  //设置增量为数组长度
    do{
        increment = parseInt(increment / 3) + 1  //重新设置增量为其三分之一
        for(i=increment;i<this.length;i++){ //从增量处开始处理
            if(this[i]<this[i-increment]){ //如果该处比增量的前一个数小
                tmp = this[i]  //后一个数保存为tmp
                for(j=i-increment;j>=0&&tmp<this[j];j-=increment){   //把后面的那个数，也就是tmp和前面的数比较，如果tmp小，那么把前面的数插到后面去
                    this[j+increment] = this[j]  //把前面的数插到后面去
                }
                this[j+increment]=tmp  //这个时侯的j应该是比较小的，在前面，所以要把tmp放进来
                console.log(this)
            }
        }
    }
    while(increment > 1)
}

let s = [21,3,52,5,43,12,3]
s.shellSort()
console.log(s)