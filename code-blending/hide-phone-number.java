/**
 * 2017-02-06
 * 핸드폰 뒷 자리 n개 가리기
 */

class HidePhoneNumber {
    static String hideNumber(String src, int n) {
        int start = src.length() - n;
        char[] srcArray = src.toCharArray();
        for (int i = start; i < src.length(); i++) {
            srcArray[i] = '*';
        }
        return String.valueOf(srcArray);
    }
    public static void main(String[] args) {
        String phone = "01012345678";
        String hidden = hideNumber(phone, 4);
        System.out.println(hidden);
    }
}
