function solution(players, callings) {
    
    const hash = new Map();
    
    players.forEach( (name , index) =>{
        hash.set(name,index);
    })
    
    callings.forEach( (name) =>{
        const index = hash.get(name);
        [players[index] , players[index-1]]  = [ players[index-1] , players[index]];
        
        hash.set(name,index-1);
        hash.set(players[index],index);
    })

    return players;
}