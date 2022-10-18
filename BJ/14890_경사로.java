import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
import java.util.StringTokenizer;
 
public class Main {
 
    static int N, X;
    static int[][] map;
 
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        StringBuilder sb = new StringBuilder();
 
        
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());
        int ans = 0;
        
        map  = new int[N][N];
       
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++)
                map[i][j] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++)
            if (checkRow(i))
                ans++;

        for (int j = 0; j < N; j++)
            if (checkCol(j))
                ans++;

        System.out.println(ans);
    }
 
    private static boolean checkRow(int i) {

        boolean[] built = new boolean[N];
        for (int j = 1; j < N; j++) {
            int prevHeight = map[i][j - 1];
            int currHeight = map[i][j];
            if (Math.abs(prevHeight - currHeight) > 1)
                return false;

            if (prevHeight < currHeight) {
                int runwayLength = 0;
                int runwayIdx = j;
                while (runwayLength < X) {
                    runwayIdx--;
                    if (runwayIdx < 0 || map[i][runwayIdx] != prevHeight || built[runwayIdx])
                        return false;
                    runwayLength++;
                }

                if (runwayLength != X) 
                    return false;
 
                for (int k = 0; k < X; k++)
                    built[j - 1 - k] = true;
            }
            // 내려가는 경사로 건설
            else if (prevHeight > currHeight) {
                int runwayLength = 1;
                int runwayIdx = j;
                while (runwayLength < X) {
                    runwayIdx++;
                    if (runwayIdx >= N || map[i][runwayIdx] != currHeight)
                        return false;
                    runwayLength++;
                }

                if (runwayLength != X) 
                    return false;

                for (int k = 0; k < X; k++)
                    built[k + j] = true;
            }
        }
        return true;
    }
 
    private static boolean checkCol(int j) {

        boolean[] built = new boolean[N];
        for (int i = 1; i < N; i++) {
            int prevHeight = map[i - 1][j];
            int currHeight = map[i][j];

            if (Math.abs(prevHeight - currHeight) > 1) 
                return false;

            // 올라가는 경사로 건설
            if (prevHeight < currHeight) {
                int runwayLength = 0;
                int runwayIdx = i;
                while (runwayLength < X) {
                    runwayIdx--;
                    if (runwayIdx < 0 || map[runwayIdx][j] != prevHeight || built[runwayIdx])
                        return false;
                    ;
                    runwayLength++;
                }
                // X만큼의 경사로 건설불가
                if (runwayLength != X)
                    return false;

 
                for (int k = 0; k < X; k++)
                    built[i - 1 - k] = true;
            }
            else if (prevHeight > currHeight) {
                int runwayLength = 1;
                int runwayIdx = i;
                while (runwayLength < X) {
                    runwayIdx++;
                    if (runwayIdx >= N || map[runwayIdx][j] != currHeight)
                        return false;
                    runwayLength++;
                }

                if (runwayLength != X)
                    return false;

                for (int k = 0; k < X; k++)
                    built[k + i] = true;
            }
        }

        return true;
    }
 
}
