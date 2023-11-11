function solution(num_list) {
    
    let odd = "";
    let even = "" 
    
    for(n of num_list){
        n%2===0? even+=n:odd+=n;
    }
    
    return Number(odd) + Number(even);
}