Array.prototype.chooseSort = function(sortMethod){
    if(this.length <= 1){
        return
    }
    let min = 0
    for(let i = 0;i<this.length;i++){
        min = i
        for(let j = i+1;j<this.length;j++){
            if(sortMethod != null){
                if(sortMethod(this[min],this[j]) > 0){
                    min = j
                }
            }
            else{
                if(this[min]>this[j])
                   min = j
            }
          
        }
        if(min != i){
            let tmp = this[i]
            this[i] = this[min]
            this[min] = tmp
        }
    }
}


let s = [21,3,52,5,43,12,3]
s.chooseSort()
console.log(s)

//该排序复杂度也是为O[n^2]

