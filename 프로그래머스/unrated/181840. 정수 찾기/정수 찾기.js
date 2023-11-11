function solution(num_list, n) {
   
    for(let a of num_list)
        if(a===n) return 1;
    
    return 0;
    
}