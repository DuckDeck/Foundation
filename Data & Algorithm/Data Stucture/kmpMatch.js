//给定两个字符串，判断其中一个是否包含另一个


String.prototype.next = function(){
    let i = 1,j = 0
    let arrNext =  [0]
    while(i<this.length){
        if(this[i] == this[j]){  //如果两个数相同
            arrNext[i] = arrNext[i-1] + 1   //保存这个数，在前一个数的基础上加1
            i++                             //向后移一位
            j++                             //向后移一位
        }
        else{     
            while(j != 0 &&this[i]!=this[j]){  //如果两者不相等，且j不是0
                j = arrNext[j-1]            //将j回调，成上一个数
            }
            if(j != 0){                     //如果 j大于0，那么后面的数是j下标的数加1
                arrNext[i] = arrNext[j] + 1
            }
            else{
                arrNext[i] = 0              //如果j=0，那么为0
            }
            i++
        }
    }
    return arrNext
}



//还有一种情况，就是需要 处理有重复的，那样会有多个index

String.prototype.myIndexOf = function(target){
     if(Object.prototype.toString.call(target) != '[object String]'){  //判断不不是string
        return -1
     }
     if(target.length > this.length){                                 //target比原字符串还要长
         return -1
     }
     let arrNext = target.next()                                //获取标记的数组
     let i = 0,j = 0
     let indexs = []
     while(i < this.length){
         if(this[i] == target[j]){                            //如果相同，比较下一个                      
            ++i
            ++j
         }
         else{
             j = arrNext[j-1] || 0                          //如果不同，那么j回调到上一个，注意不能小于0
             if(j==0){                                      //如果j==0，从下一个数开始比较
                ++i
             }
         }
         
         if(j == target.length){                            //已经比较到最后一个，说明找到match
             indexs.push(i - j)                             //i-j就是index处的位置，可以保存到一个数组里
             //return i-j                                   如果不贪心，可以直接返回
         }
     }
     if(indexs.length <= 0){                                //如果一个也找不到，返回-1
         return -1
     }
     else{
         return indexs[0]                                //找到了，返回第一个
     }

 }

 let i = "abxabcabcaby".myIndexOf("bc")
 console.log(i)