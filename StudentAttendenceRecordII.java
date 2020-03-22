public class StudentAttendenceRecordII {
    public static void main(String[] args) {
        StudentAttendenceRecordII stu = new StudentAttendenceRecordII();
        stu.checkRecord(10);    
    }
    
    long mod=(long) 1e9+7;
    public int checkRecord(int n) {
        int[] state = new int[] {1, 1, 0, 1, 0, 0};
        int cnt=1;
        while (cnt<n) {

            int[] state_new = new int[6];
            state_new[0]=state[0]+state[1]+state[2]; state_new[0] %= mod;
            state_new[1]=state[0]; state_new[1] %= mod;
            state_new[2]=state[1]; state_new[2] %= mod;
            state_new[3]=state[0]+state[1]+state[2]+state[3]+state[4]+state[5]; state_new[3] %= mod;
            state_new[4]=state[3]; state_new[4] %= mod;
            state_new[5]=state[4]; state_new[5] %= mod;

            state=state_new;
            cnt+=1;
        }

        int ans=0;
        for (int i=0; i<6; i++) {
            ans+=state[i];
            ans%=mod;
        }
        System.out.println(ans+" "+mod);
        return ans;
    }
}