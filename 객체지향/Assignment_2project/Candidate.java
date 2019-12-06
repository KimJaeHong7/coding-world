package assignment2;


public class Candidate extends Student{
	
	private int voteNum;
	
	public int getVoteNum() {
		return voteNum;
	}

	public void setVoteNum(int voteNum) {
		this.voteNum = voteNum;
	}

	public void increase() {
		this.voteNum++;
	}
	public Candidate(int Num, Department D, String Na, int voteNum) {
		super(Num, D, Na);
		this.voteNum = voteNum;
	}
	
	@Override
	public int compareTo(Object arg0) {
		
		Candidate temp = (Candidate)arg0;
		if(this.voteNum > temp.voteNum)	return 1;
		else if (this.voteNum == temp.voteNum)	 return 0;
		else return -1;
	}

	
	public String toString() {
		return 
				"======== Elected Candidate ========" +
				"\r\n"+
				"Department Name: " + super.getdepartment().getdepName() + "\r\n" +
				"name: " + super.getname() + "\r\n" +
				"Student_id: "+ super.getid() + ""
						+ "\r\n"+
				"Votes: "+ this.getVoteNum() + "\r\n" +
				"==================================="
				;
		
	}
}
