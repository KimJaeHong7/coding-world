package assignment2;

import java.util.ArrayList;

public class Department {
	
	private int depNum;
	private String depName;
	ArrayList<Candidate> candidate = new ArrayList<Candidate>();
	ArrayList<Student> stu = new ArrayList<Student>();
	
	public Department(int num, String name) {
		this.depNum = num;
		this.depName = name;
	}
	
	public int getdepNum() {
		return depNum;
	}
	public void setdepNum(int depNum) {
		this.depNum = depNum;
	}
	public String getdepName() {
		return depName;
	}
	public void setdepName(String depName) {
		this.depName = depName;
	} 
	
	public Candidate highVotes() {
		
		Candidate result = null;
		
		for(Candidate a : candidate) {
			if(result == null)	result = a;
			if(result.getVoteNum()< a.getVoteNum())	result = a;
		}
		
		return result;
	}
}
