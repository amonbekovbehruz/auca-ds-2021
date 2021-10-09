import java.util.Scanner;

public class Java {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()) {
            String str = scanner.nextLine();
            str.trim().toLowerCase();
            String strCopy = "";
            String strCopy2 = "";

            for (int i = str.length() - 1; i >= 0; i--) {
                if (str.charAt(i) >= 97 && str.charAt(i) <= 122) {
                    strCopy += (str.charAt(i));
                }
            }
            for (int j = 0; j < str.length(); j++) {
                if (str.charAt(j) >= 97 && str.charAt(j) <= 122) {
                    strCopy2 += (str.charAt(j));
                }
            }

            if (strCopy.equals(strCopy2)) {
                System.out.println("palindrome");

            } else {
                System.out.println("not a palindrome");
            }
        }
    }
}
