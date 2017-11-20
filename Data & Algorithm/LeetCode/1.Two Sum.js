//给定一个整数数组，返回两个数字的索引，使得它们加起来等于一个特定的目标值。

//您可以假设每个输入都有一且只有一个答案，数组中每个元素只能使用一次。

/*
Example
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/


function twoSum(array,target){
    let len = array.length
    let tmp  = 0
    let a = 0
    let b = 0
    for(let i = 0;i<len;i++){
        tmp = target - array[i]
        if(tmp > 0){
            for(let j = i;j<len;j++){
                if(array[j] == tmp){
                    a = i
                    b = j
                    break
                }
            }
        }
    }
    if(a===b & b=== 0){
        return undefined
    }
    return [a,b]
}

let test = [3,2,4]x                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
let target = 6
let result = twoSum2(test,target)
console.log(result)

//算法复杂度o[n^2],不理想
//js没有hashmap
//可以用js模仿hashmap
//

function twoSum2(array,target){
    let len = array.length
    let exist = {}
    for(let i = 0;i<len;i++){
        if(exist[target-array[i]]!==undefined){ //判断exist有没有另一半
            return [exist[target - array[i]],i]
        }
        exist[array[i]] = i //如果 不存在，就添加进来，再记录index
    }
}