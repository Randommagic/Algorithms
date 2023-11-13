function solution(s) {
    const str = [...s];
    const ans = [];
    
    for(let i = 0 ; i < s.length ; i++){
        const c = str[i];
        let idx = -1 ;
        let temp = 1;
        for(let j = i - 1 ; j >= 0 ; j--){
            if(c === str[j]){       
                idx = temp;
                break;
            }
            temp++;
        }
        ans.push(idx);
    }
    return ans;
}