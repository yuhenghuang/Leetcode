public class StudentAttendenceRecordI {
    public static void main(String[] args) {
        System.out.println(checkRecord("PPALLP"));
    }

    public static boolean checkRecord(String s) {
        int cnt_A, cnt_L;
        cnt_A=0;
        cnt_L=0;
        for (int i=0; i<s.length(); i++) {
            if (s.charAt(i)=='A') {
                cnt_A+=1;
            }

            if (s.charAt(i)=='L') {
                cnt_L+=1;
            }
            else {
                System.out.println("Act");
                cnt_L=0;
            }

            if (cnt_A>1 || cnt_L>2) {
                return false;
            }
        }
        return true;
    }
}