//2015.11.20
import java.util.StringTokenizer;
import java.io.IOException;

public class StringCompare {
    public static void main(String[] Arguments) throws IOException {

	String usuario = "Jorman";
	String password = "14988611";

	String strDatos = "Jorman 14988611";
	StringTokenizer tokens = new StringTokenizer(strDatos, " ");
	int nDatos = tokens.countTokens();
	String[] datos = new String[nDatos];
	int i = 0;

	while (tokens.hasMoreTokens()) {
	    String str = tokens.nextToken();
	    datos[i] = str;
	    i++;
	}

	//System.out.println (usuario);
	if ((datos[0] == usuario)) {
	    System.out.println("WORKING");
	}
        if (datos[0].equals(usuario)) {
            System.out.println("using String.equals()");
        }
    }
}
