package algorithms;

import java.util.ArrayList;
import java.util.List;

public class ArrayListExample {
	
	public static void main(String[] args) {
		
		//creating an array list
		List<String> students = new ArrayList<>();
		
		students.add("Ram");
		students.add("shyam");
		students.add("hari");
		
		//Iterating through an array list
		for(String student:students) {
			System.out.print(student);
		}
		
		
	}

}
