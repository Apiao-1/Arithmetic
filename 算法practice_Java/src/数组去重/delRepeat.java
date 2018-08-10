package 数组去重;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class delRepeat {
	public static void main(String []args) {
		String[] array = {"a","b","c","c","d","e","e","e","a"};  
		List<String> result = new ArrayList<>();
		boolean flag;
		for(int i=0;i<array.length;i++){  
		    flag = false;  
		    for(int j=0;j<result.size();j++){  
		        if(array[i].equals(result.get(j))){  
		            flag = true;  
		            break;  
		        }  
		    }  
		    if(!flag){  
		        result.add(array[i]);  
		    }  
		}  
		String[] arrayResult = (String[]) result.toArray(new String[result.size()]);  
		System.out.println(Arrays.toString(arrayResult)); 
		System.out.println("Hello World");
	}
}
