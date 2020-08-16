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

let s = [21,3,52,5,43,12,3]
s.quickSort()
console.log(s)