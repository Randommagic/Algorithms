function solution(name, yearning, photo) {
    const hash = new Map();
    let result = [];
    
    name.forEach( (n,index)=>{
        hash.set(n, yearning[index]);
    })
    
    photo.forEach((arr)=>{
        let sum = 0;
        arr.forEach((n)=>{
            if(hash.has(n)){
                sum += hash.get(n);
            }    
        });
        result.push(sum);
    });
    
    
    return result;
}