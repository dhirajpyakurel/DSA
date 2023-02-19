package algorithms;

import java.util.LinkedList;
import java.util.List;

public class LinkedListExample {
	
	public static void main(String[] args) {
		List<String> students = new LinkedList<>();
		
		students.add("ram");
		students.add("gopal");
		students.add("shyam");
		
		
		System.out.println(students.contains("shyam"));
		
		for(String student:students) {
			System.out.println(student);
		}
		
	}

}
