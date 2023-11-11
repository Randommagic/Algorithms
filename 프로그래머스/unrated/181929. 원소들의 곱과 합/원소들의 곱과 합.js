function solution(num_list) {
    let mult = 1;
    let add = 0;
    
    for(n of num_list){
        mult *= n;
        add += n;
    }
    
    return mult < add*add?1:0;
    
    
}