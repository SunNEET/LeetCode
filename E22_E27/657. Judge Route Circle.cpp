class Solution {
    // 水題...
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(int i=0;i<moves.length();i++) {
            if(moves[i]=='U')
                x-=1;
            else if(moves[i]=='D')
                x+=1;
            else if(moves[i]=='L')
                y-=1;
            else
                y+=1;
        }
        return (x==0 && y==0);
    }
};