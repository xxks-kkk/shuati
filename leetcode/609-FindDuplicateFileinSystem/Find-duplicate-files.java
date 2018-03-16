// Question: given a file path, find duplicate files in the file system and list their paths in List<List<String>>
// Duplicate files: files with the same content but different file names
// Example:
// root/a 1.txt("abcd") 2.txt("efgh")
// root/c 3.txt("abcd")
// root/c/d 4.txt("efgh")
// Output: [[root/a/1.txt, root/c/3.txt], [root/a/2.txt, root/c/d/4.txt]]

// Idea: Your solution needs to be tackle a couple of problems: obtaining a list of all the files in the file system (e.g. via DFS), binning the lists into 
// possible matches, repeat via swappable heuristics until your certainty is 100%. (eg size 1st, md5 2nd, byte stream 3rd)
// 1. parse the whole file system
//		File class method: boolean isDirectory(), booelan isFile(), String[] list(), long length(), read(buffer, offset, size)
// 2. Binning the lists into possible matches
//		1) hashing: MD5, SHA1, SHA256
//		2) metadata: file size; the first 1kb of data, the second 1kb of data....

//<----------------------------------------------------------------------------------------------------------------------------------->
// Easy version: obtain the list of all files in the file system and hash them into different groups 
public class Solution{
	public List<List<String>> findDuplicates(String path){
		List<List<String>> res = new ArrayList<>();
		if(path == null || path.length == 0) return res;

		List<String> filesList = dfs(path); // list all files in the directory
		Map<String, List<String>> hMap = new HashMap<>(); // map: hash value ---> list of file paths

		// Hashing each file and put it into according bucket in the HashMap
		for(String f : filesList){
			File file = new File(f);
			String hash = getMD5(file);

			if(hMap.containsKey(hash)){
				List<String> value = hMap.get(hash);
				value.add(f);
				hMap.put(hash, value);
			}

			else{
				List<String> value = new ArrayList<>();
				value.add(f);
				hMap.put(hash, value);
			}
		}

		for(List<String> value : hMap.values())
			if(value.size() > 1)
				res.add(value);

		return res;
	}

	// Use dfs to get all the files in the directory, return the path of all files
	private List<String> dfs(String path){
		List<String> filesList = new ArrayList<>(); 
		Stack<String> st = new Stack<>();
		st.push(path);

		while(!st.empty()){
			String curPath = st.pop();
			File file = new File(curPath);

			if(file.isFile()) fileList.add(curPath);

			// File has subdirectories
			else if(file.isDirectory()){
				String[] subDir = file.list();
				for(String s : subDir){
					String newPath = curPath + "/" + s;
					st.push(newPath);
				}
			}
		}

		return filesList;
	}
}

//<----------------------------------------------------------------------------------------------------------------------------------->
// Follow up: If the directory only contains a few duplicate files, we still need to search through the whole directory. 
// MD5 is slow if each file is very large. How can we optimize the above solution?
// Optimize: use the metadata of the file to first hashing the files and then use MD5 to hash the files.
public class Solution{
	public List<List<String>> findDuplicates(String path){
		List<List<String>> res = new ArrayList<>();
		if(path == null || path.length == 0) return res;

		List<List<String>> filesList = dfs(path); // files with same file size
		for(List<String> sameSizeList : filesList){
		
		// Iterate through the files with the same size (potentially to be duplicate files)
		Map<String, List<String>> hMap = new HashMap<>(); // map: hash value ---> list of file paths, hash the files by hash value
		for(String f : sameSizeList){
			File file = new File(f);
			String hash = getMD5(file);

			if(hMap.contains(hash)){
				List<String> list = hMap.get(hash);
				list.add(f);
				hMap.put(hash, list);
			}

			else{
				List<String> list = new ArrayList<>();
				list.add(f);
				hMap.put(hash, list);
			}
		}

		for(List<String> value : hMap.values())
			if(value.size() > 1)
				res.add(value);
		}

		return res;
	}

	// Private helper function that uses dfs to return the list of all the files in the directory, divided into groups by their sizes.
	private List<List<String>> dfs(String path){
		List<List<String>> filesList = new ArrayList<>();
		Map<Integer, List<String>> hMap = new HashMap<>(); // map: file size ---> list of file paths, hash the files by size
		Stack<String> st = new Stack<>();
		st.push(path);

		while(!st.empty()){
			String curPath = st.pop();
			File file = new File(curPath);

			if(file.isFile()){
				long size = file.length();
				if(hMap.contains(size)){
					List<String> list = hMap.get(size);
					list.add(curPath);
					hMap.put(size, list);
				}

				else{
					List<String> list = new ArrayList<>();
					list.add(curPath);
					hMap.put(size, list);
				}
			}

			else if(file.isDirectory()){
				String[] subDir = file.list();
				for(String s : subDir){
					String newPath = curPath + "/" + s;
					st.push(newPath); 
				}
			}
		}

		for(List<String> value : hMap.values())
			if(value.size() > 1)
				filesList.add(value);

		return filesList;
	}
}

//<----------------------------------------------------------------------------------------------------------------------------------->
// Further optimization: we do not calculate MD5 value of the whole file. Instead we divide the file into blocks of 1kb.
// First hash the file with MD5 of the first 1kb and then hash by the second 1kb.....and so on.
File file = new File(path);
FileInputStream fis = new FileInputStream(file);
byte[] buffer = new byte[1024];//读1kb
int rc = fis.read(buffer, 0, 1024);
while (rc != -1) {
	hash(buffer);
	rc = fis.read(buffer);
}

//<----------------------------------------------------------------------------------------------------------------------------------->
// Follow up question: Are there any circumstances which could lead to false negative?
