function solution(my_string, k) {
    // return my_string.repeat(k);
    let answer = '';
    for(let i = 0; i < k ;i++)
       answer = answer + my_string
    return answer;
}