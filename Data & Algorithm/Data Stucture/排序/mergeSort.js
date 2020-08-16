Array.prototype.mergeSort = function(sortMethod){
    if(this.length <= 1){
        return
    }
    mSort(this,0,this.length - 1)
}

function mSort(array,start,end){
    if(start < end){
        let middle = parseInt((start + end) / 2)
        mSort(array,start,middle)
        mSort(array,middle + 1,end)
        merge(array,start,middle,end)
    }
}

function merge(array,start,middle,end){
    let startIndex = start
    let middleIndex = middle+1
    let tmp = []
    let tempIndex = 0
    while(startIndex<=middle&&middleIndex<=end){
        if(array[startIndex]<=array[middleIndex]){
            tmp[tempIndex ++ ] = array[startIndex++]
        }
        else{
            tmp[tempIndex ++ ] = array[middleIndex++]
        }
    }
    while(startIndex<=start){
        tmp[tempIndex ++ ] = array[startIndex++]
    }
    while(middleIndex<=end){
        tmp[tempIndex ++ ] = array[middleIndex++]
    }
    tempIndex = 0
    for(let i = start;i<=end;i++){
        array[i] = tmp[tempIndex++]
    }
}



let s = [21,3,52,5,43,12,3]
s.mergeSort()
console.log(s)

//该排序复杂度也是为O[n^2]

