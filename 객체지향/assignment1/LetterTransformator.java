package assignment1;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class LetterTransformator {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner fileIn1 = null;
		Scanner fileIn2 = null;
		PrintWriter fileIn3 = null;
		KeyValue properties[] = new KeyValue[100];
		KeyValue template[] = new KeyValue[100];
		KeyValue output[] = new KeyValue[100];
		String nkey="";
		try
		{	
			int cnt = 0;
			String str[] = new String[100];
			fileIn1 = new Scanner(new FileInputStream("properties.txt"));
			fileIn2 = new Scanner(new FileInputStream("template_file.txt"));
			fileIn3 = new PrintWriter("output_file.txt");
			while(fileIn1.hasNext()) {
				properties[cnt++] = new KeyValue(fileIn1.nextLine());
			}
			while(fileIn2.hasNext()) {
				String getline = fileIn2.nextLine();
				for(int k=0; k<cnt;k++) {
					str[k] = "{"+properties[k].getKey()+"}";
					getline = getline.replace(str[k], properties[k].getValue());	
						
				}fileIn3.println(getline);
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		finally {
			try {
				if(fileIn1 != null) fileIn1.close();
				if(fileIn2 != null) fileIn2.close();
				if(fileIn3 != null) fileIn3.close();
			}
			catch (Exception e2) {
				e2.printStackTrace();
			}
		}
	}

}
