enum RoomAttr {BigBed, SingleBed, DoubleBed, President, Couple}

class HotelMS {
  public static void main(String[] args) {
    Hotel htl = new Hotel(3, 5);
    htl.generateRooms(0.8);
    htl.printRooms();
    htl.bookRoom("304");
    htl.bookRoom("205");
    htl.checkOut("301");
    htl.checkOut("304");
    htl.checkOut("404");
    htl.printRooms();
  }
}

class Hotel {
  private int height, width;
  Room[][] rooms;
  private static RoomAttr[] types = RoomAttr.values();

  Hotel(int h, int w) {
    height = h;
    width = w;
    rooms = new Room[h][w];
  }

  public void bookRoom (String roomNum) {
    Room room = getRoom(roomNum);
    if (room==null || !room.roomEmpty) 
      System.out.println("Room " + roomNum + " is not available");
    else {
      room.setRoomEmpty(false);
      System.out.println("Room " + roomNum + " is booked successfully.");
    }
  }

  public void checkOut(String roomNum) {
    Room room = getRoom(roomNum);
    if (room==null || room.roomEmpty) 
      System.out.println("Room " + roomNum + " is illegal.");
    else {
      room.setRoomEmpty(true);
      System.out.println("Room " + roomNum + " checked out.");
    }
  }

  public void printRooms() {
    for (int i=0; i<height; ++i)
      for (int j=0; j<width; ++j)
        rooms[i][j].printStatus();
  }



  void generateRooms(double rate) {
    for (int i=0; i<height; ++i)
      for (int j=0; j<width; ++j) {
        rooms[i][j] = new Room(String.valueOf(i*100 + j + 101), randomType(), Math.random()<rate);
      }
  }

  private Room getRoom(String roomNum) {
    int tmp = Integer.parseInt(roomNum);
    int h = tmp / 100 - 1, w = tmp % 100 - 1;
    if (h<0 || h>=height || w<0 || w>=width) {
      System.out.println("Room " + roomNum + " does not exist.");
      return null;
    }
    else 
      return rooms[h][w];
  }

  private RoomAttr randomType() {
    return types[(int) (Math.random() * types.length)];
  }
}


class Room {
  RoomAttr type;
  String roomNum;
  boolean roomEmpty;
  Room(String r, RoomAttr t, boolean e) {
    roomNum = r;
    type = t;
    roomEmpty = e;
  }

  void setRoomEmpty(boolean b) {
    roomEmpty = b;
  }

  public void printStatus() {
    System.out.println("Room Num: " + roomNum + "\tType: " + type + "\tisEmpty: " + roomEmpty);
  }
}