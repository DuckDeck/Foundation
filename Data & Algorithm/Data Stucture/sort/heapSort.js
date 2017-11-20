Array.prototype.heapSort = function(sortMethod){
    if(this.length <= 1){
        return
    }
    let i = 0
    for(i = parseInt(this.length / 2);i>0;i--){
        headAdjust(this,i,this.length)
    }
    for(i = this.length;i>1;i--){
        let tmp = this[i-1]
        this[i-1] = this[0]
        this[0] = tmp
        headAdjust(this,1,i-1)
    }
}

function headAdjust(array,i,length){//索引要减1是为了和堆的索引同步，length,是因为最大的数已经确定了，最后一个数不需要排序了
    let tmp  = array[i-1]
    let j = 0
    for(j = i * 2;j<=length;j*=2){ //这是一个棵完全二叉树,j是i的左孩子.
        if(j<length && array[j-1]<array[j]){ //比较i的两个左右孩子,选出大的那一个
            ++j                 //如果右孩子大于左孩子,那个++j,把j指为右孩子
        }
        if(tmp>=array[j-1]){ //如果右孩子的值比双亲还要小,那跳出循环,不需要做交换,否则要做交换
            break
        }
        array[i-1] = array[j-1] //将较大孩子的值给其双亲（父母）
        i=j //将双亲指向较大的孩子重新循环，这里可能有问题。
    }
    array[i-1]=tmp //此时的i已经是先前i的孩子了,那么将先前双亲存的值赋给此孩子(同时是下两个孩子的双亲).
    console.log(array)
}

let s = [21,3,52,5,43,12,3,100,31,1,76]
s.heapSort()
console.log(s)