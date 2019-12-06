package assignment2;

import java.util.Random;

public class Student implements Voter{
	
	private String name;
	private int id;
	private Department department;
	private int grade;
	
	Random random = new Random();
	
	public String getname() {
		return name;
	}
	public void setname(String name) {
		this.name = name;
	}
	public int getid() {
		return id;
	}
	public void setid(int id) {
		this.id = id;
	}
	public Department getdepartment() {
		return department;
	}
	public void setdepartment(Department department) {
		this.department = department;
	}
	public int getgrade() {
		return grade;
	}
	public void setgrade(int grade) {
		this.grade = grade;
	}
	
	public Student(int Num, Department D, String Na) {
		this.id = Num;
		this.department = D;
		this.name = Na;
	}
	
	@Override
	public void vote() {
		int i = random.nextInt(this.department.candidate.size()-1);
		this.department.candidate.get(i).increase();
	}
	
	@Override
	public int compareTo(Object arg0) {
		// TODO Auto-generated method stub
		Student other = (Student)arg0;
		return this.id - other.id;
	}
}
