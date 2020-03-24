import static java.lang.System.in;
import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) {
         Scanner in = new Scanner(System.in);
    int t,n,k=1;
    t = in.nextInt();
    while(t>0){
         n = in.nextInt();
        BigInteger a = in.nextBigInteger();
        BigInteger b = in.nextBigInteger();
        BigInteger carry;
       
        carry = (a.multiply(b)).divide(a.gcd(b));
       
        for(int i=3; i<=n; i++){
            a = in.nextBigInteger();
            carry = (carry.multiply(a)).divide(carry.gcd(a));
        }
       
       
        System.out.println("Case "+k+": "+carry);
     
        t--;
        k++;
    }
   
    System.exit(0);
   
    }
   
}
