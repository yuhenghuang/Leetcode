

class ValidIpAddress {
  public static void main(String[] args) {
    ValidIpAddress obj = new ValidIpAddress();
    System.out.println(obj.validIPAddress("172.16.254.1"));
    System.out.println(obj.validIPAddress("172.16.254.01"));
    System.out.println(obj.validIPAddress("2001:0sb8:85a3:0000:0000:8a2e:0370:7334"));
    System.out.println(obj.validIPAddress("2001:db8:85a3:0:0:8A2E:0370:7334"));
    System.out.println(obj.validIPAddress("2001:0fb8:85a3::8A2E:0370:7334"));
    System.out.println(obj.validIPAddress("02001:0db8:85a3:0000:0000:8a2e:0370:7334"));
    System.out.println(obj.validIPAddress("1e1.4.5.6"));
  }
  public String validIPAddress(String IP) {
    if (IP.contains(".") && IP.contains(":"))
      return "Neither";
    else if (IP.contains("."))
      return ipv4(IP);
    else if (IP.contains(":"))
      return ipv6(IP);
    else
      return "Neither";
  }

  String ipv4(String IP) {
    if (IP.charAt(0)=='.' || IP.charAt(IP.length()-1)=='.') return "Neither";
    String[] sp = IP.split("\\.");
    if (sp.length!=4) return "Neither";
    for (int i=0; i<4; ++i) 
      if (sp[i].length()>3 || sp[i].length()==0 || !sp[i].matches("[0-9]+") || (sp[i].length()>1 && sp[i].charAt(0)=='0') || Integer.parseInt(sp[i])>255)
        return "Neither";
    return "IPv4";
  }

  String ipv6(String IP) {
    if (IP.charAt(0)==':' || IP.charAt(IP.length()-1)==':') return "Neither";
    String[] sp = IP.split(":");
    if (sp.length!=8) return "Neither";
    for (int i=0; i<8; ++i)
      if (sp[i].length()>4 || sp[i].length()==0 || !sp[i].matches("[0-9a-fA-F]+"))
        return "Neither";
    return "IPv6";
  }
}