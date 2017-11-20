//使用一个标志来标记, 当进行一个一个冒泡比对时,如果已经有序,就不会交换数据,也就是flag为false,以后不会再进行比对了
Array.prototype.bubbleSort = function(sortMethod){
    if(this.length <= 1){
        return
    }
    let flag = true
    for(let i = 0; i < this.length && flag ;i++){
        flag = false
        for(let j = this.length - 2;j>=i;j--){
            if(sortMethod!=null){
                if(sortMethod(this[j],this[j+1]) == 1){
                    let tmp = this[j]
                    this[j] = this[j+1]
                    this[j+1] = tmp
                    flag = true
                }
            }
            else{
                if(this[j]>this[j+1]){
                    let tmp = this[j]
                    this[j] = this[j+1]
                    this[j+1] = tmp
                    flag = true
                }
            }
        }
    }
}



let s = [21,3,52,5,43,12,3]
s.bubbleSort()
console.log(s)