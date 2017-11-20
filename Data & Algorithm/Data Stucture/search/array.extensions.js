if(!Array.prototype.sequentialSearch){
    Array.prototype.sequentialSearch = function(key){
        let i = 0
        while(i<this.length){
            if(this[i] === key){
                console.log("search for " + key + "the result is " + i)
                return i
            }
            i++
        }
        return -1
    }
}
if(!Array.prototype.binarySearch){
    Array.prototype.binarySearch = function(key){
        if(this.length == 0){
            return -1
        }
        let low = 0
        let high = this.length - 1
        let middle = 0
        while(low < high){
             middle = parseInt((low + high) / 2)
             if(this[middle]<key){
                 low = middle + 1
             }
             else if (this[middle] == key){
                 console.log("search for " + key + "the result is " + middle)
                return middle
             }
             else{
                 high = middle + 1
             }
        }
        return -1
    }
}

if(!Array.prototype.interpolationSerach){
    Array.prototype.interpolationSerach = function(key){
        if(this.length == 0){
            return -1
        }
        let low = 0
        let high = this.length - 1
        let middle = 0
        while(low < high){
             middle = low + parseInt((high - low) * (key - this[low]) / (this[high] - this[low]))
             if(this[middle]<key){
                 low = middle + 1
             }
             else if (this[middle] == key){
                console.log("search for " + key + "the result is " + middle)
                return middle
             }
             else{
                 high = middle + 1
             }
        }
        return -1
    }
}


if(!Array.prototype.fibonacciSearch){
    Array.prototype.fibonacciSearch = function(key){
        if(this.length == 0){
            return -1
        }
        let low = 0    
        let high = this.length - 1
        let middle = 0
        let i = 0
        let k = 0
        let F = Fibonacci.nums(high + 1)  //获取finonacci数组
        while(high > F[k] - 1){      //计算n位于finonacci数组的位置
            k ++
        }
        for(i = high;i<F[k] - 1;i++){   //将不满的数组补全
            this[i] = this[high]        //后面的数都是最后一个
        }
        while(low <= high){
            middle = low + F[k-1] -1    //获取第一个middle
            if(key < this[middle]){
                high = middle - 1
                k = k-1
            }
            else if(key > this[middle]){
                low = middle + 1
                k = k-1
            }
            else {
                if(middle <= high){
                    return middle
                }
                return high
            }
        }
        return -1

    }
}


class Fibonacci{
   static  nums(length) {
        if(!Number.isInteger(length)){
            throw Error('n must be num')
        }
        let tmp = [1]
        if(length <= 0){
            return tmp
        }
        let i = 1
        let num = 0
        while(i < length){
            tmp.push(num + tmp[i-1])
            num = tmp[i - 1]
            i++
        }
        return tmp
   }

   static index(index){
        return Fibonacci.nums(index + 1)[index]
   }
}



if(!Array.prototype.fibonacciNums){
    Array.prototype.fibonacciNums = function(length){
        if(!Number.isInteger(n)){
            throw Error('n must be num')
        }
        let tmp = [1]
        if(n <= 0){
            return tmp
        }
        let i = 1
        let num = 0
        while(i < n){
            tmp.push(num + tmp[i-1])
            num = tmp[i - 1]
            i++
        }
        return tmp
    }
}

if(!Array.prototype.quickSort){
    Array.prototype.quickSort = function(sortMethod){
        if(this.length<=1){
            return
        }
        qSort(this,0,this.length - 1)
    }
    
    function qSort(array,low,high){
        let pivot = 0
        if(low < high){
            pivot = partition(array,low,high)
            qSort(array,low,pivot - 1)
            qSort(array,pivot + 1,high)
        }
    }
    
    function partition(array,low,high){
        let pivotKey = array[low]
        while(low < high){
            while(low < high && array[high] >= pivotKey)
                high --
            let tmp = array[low]
            array[low] = array[high]
            array[high] = tmp
            while(low < high && array[low] < pivotKey)
                low ++
            tmp = array[low]
            array[low] = array[high]
            array[high] = tmp
        }
        return low
    }
}