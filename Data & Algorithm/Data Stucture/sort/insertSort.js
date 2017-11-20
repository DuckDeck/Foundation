Array.prototype.insertSort = function(sortMethod){
    if(this.length <= 1){
        return
    }
    for(let i = 1;i<this.length;i++){
        if(sortMethod){
            if(sortMethod(this[i-1],this[i])>0){
                this[0] = this[i]
                for(let j=i-1;this[j]>this[0];j--){
                    this[j+1]=this[j]
                }
                this[j+1] = this[0]
            }
        }
        else{
            if(this[i]<this[i-1]){  //如果后面一个数比前一个数小，那么就要把为个数插到前面的有序数组里的合适位置
               let tmp = this[i] //把这个数保存在临时变量里
               let j = 0
               for(j = i - 1;this[j]>tmp;j--){ //tmp一个一个和前一数比，直到比前一个数小，而在同时，将比其大的数向后移一个位置，方面插入这个数
                 this[j+1] = this[j] //将这个数后移动，一次移动一个，直到前面的娄比tmp小为止
               } 
               this[j+1] = tmp  //这个时侯j刚好是前面比tmp小的数，后面比tmp 大的数，将这个数插入
            }
       }
    }
}


let s = [21,3,52,5,43,12,3]
s.insertSort()
console.log(s)