package assignment1;

import java.util.StringTokenizer;

public class KeyValue {
	private String key;
	private String value;

public KeyValue(String a) {
	StringTokenizer st = new StringTokenizer(a,"=");
	this.key=st.nextToken();
	this.value=st.nextToken();
}

public KeyValue(String a, String b) {
	this.key  = a;
	this.value = b;
}

	
public String getKey() {
	return key;
}

public String getValue() {
	return value;
}
}
