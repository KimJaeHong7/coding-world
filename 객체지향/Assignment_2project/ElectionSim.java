package assignment2;

import java.util.ArrayList;
import java.util.Collections;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class ElectionSim {

	private String input1;
	private String input2;
	private String output;
	ArrayList<Department> dep = new ArrayList<Department>(); 
	ArrayList<Candidate> can = new ArrayList<Candidate>();
	
	public ElectionSim(String input1, String input2, String output) {
		
		this.input1 = input1;
		this.input2 = input2;
		this.output = output;
	
        BufferedReader br = null;
        String line = "";
        String comma = ",";

        try {
        		InputStream in = new FileInputStream(new File(input1));
            br = new BufferedReader(new InputStreamReader(in));
            line = br.readLine();
            while ((line = br.readLine()) != null) {
                String[] stringTmp = line.split(comma);
                Department tmp = new Department(Integer.parseInt(stringTmp[0]), stringTmp[1]);
                dep.add(tmp);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        
        try {
        		InputStream in = new FileInputStream(new File(input2));
            br = new BufferedReader(new InputStreamReader(in));
            line = br.readLine();
	        while ((line = br.readLine()) != null) {
	           String[] stringTmp = line.split(comma);
	           Student Tmp = new Student(Integer.parseInt(stringTmp[0]), dep.get(Integer.parseInt(stringTmp[1])-1), stringTmp[2]);
	           dep.get(Integer.parseInt(stringTmp[1])-1).stu.add(Tmp);
	           if(stringTmp[3].equals("TRUE")) {
	        	   		Candidate cTmp = new Candidate(Integer.parseInt(stringTmp[0]), dep.get(Integer.parseInt(stringTmp[1])-1), stringTmp[2], 0);
	        	   		dep.get(Integer.parseInt(stringTmp[1])-1).candidate.add(cTmp);
	            }
	         }
	    } catch (FileNotFoundException e) {
	         e.printStackTrace();
	    } catch (IOException e) {
	         e.printStackTrace();
	    } finally {
	         if (br != null) {
	        	 	try {
	        	 		br.close();
	        	 	} catch (IOException e) {
	        	 		e.printStackTrace();
	            }
	        }
	    }
    }	
	
	private void saveData() {
		
		Collections.sort(can);
BufferedWriter bw = null;
		
		try {
			
			bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(output), "UTF8"));
			for(Candidate temp : can) {
				bw.write(temp.toString());
				bw.newLine();
			}
		}
		catch(IOException e) {
			e.printStackTrace();
		}
		finally {
			try {
				bw.flush();
			}
			catch(IOException e) {
				e.printStackTrace();
			}
		}
	}
	public void runSimulation() {
		
		for(Department deTemp : dep) {
			for(Student temp : deTemp.stu) {
				temp.vote();
			}
		}
		
		for(Department deTemp : dep) {
		
			Candidate temp = deTemp.highVotes();
			can.add(temp);
		}
		
		saveData();
	}
}
