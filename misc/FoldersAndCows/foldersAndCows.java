import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Folder{
	int id = 0; 
	boolean access = false; // true: shared, false: confidential
	List<Folder> children = new LinkedList<>(); 
	List<Integer> cows = new LinkedList<>();
	int in = 0;
	int out = 0;

	Folder(int id, boolean access){
		this.id = id;
		this.access = access;
		in = 0;
		out = 0;
	}

	void appendCow(List<Integer> newCows){
		cows.addAll(newCows);
	}
}

public class Solution {
    private static Folder findFolder(List<Folder> folders, int id){
		for(Folder folder: folders)
			if(folder.id == id)
				return folder;
		return null;
	}
    
    private static void traverse(int[] cows, Folder root){
		if(root.out == 0)
			for(int i : root.cows)
				cows[i]++;
		for(Folder f: root.children){
			if(f.access)
				f.appendCow(root.cows);
			traverse(cows, f);
		}
	}
    
    public static void main(String args[] ) throws Exception {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        Scanner scanner = new Scanner(System.in);
		List<Folder> folders = new ArrayList<>();


		// parse and build folders
		int Q = scanner.nextInt();
		int M = scanner.nextInt();
		int N = scanner.nextInt();
		while(M-- > 0){
			Folder f = new Folder(scanner.nextInt(), true);
			folders.add(f);
			int K = scanner.nextInt();
			while(K-- > 0)
				f.cows.add(scanner.nextInt());
		}
		while(N-- > 0){
			Folder f = new Folder(scanner.nextInt(), false);
			folders.add(f);
			int K = scanner.nextInt();
			while(K-- > 0)
				f.cows.add(scanner.nextInt());
		}

		// parse and build trees
		int G = scanner.nextInt();
		while(G-- > 0){
			int U = scanner.nextInt();
			int V = scanner.nextInt();
			Folder u = findFolder(folders, U);
			Folder v = findFolder(folders, V);
			if(u != null & v != null){
				u.children.add(v);
				u.out++;
				v.in++;
			}
		}

		// traverse
		int numLeaf = 0;
		int[] cows = new int[Q];
		for(int i = 0; i < folders.size(); i++){
			if(folders.get(i).in == 0)
				traverse(cows, folders.get(i));
			if(folders.get(i).out == 0)
				numLeaf++;
		}

		List<Integer> res = new ArrayList<>();
		for(int i = 0; i < Q; i++)
			if(cows[i] < numLeaf)
				res.add(i);

		for(int i = 0; i < res.size(); i++)
			System.out.print(res.get(i) + " ");
	}
}
