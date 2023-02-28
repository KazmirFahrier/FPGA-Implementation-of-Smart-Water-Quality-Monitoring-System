module test(mq7in,waterLevel,leds,leds2, mqled, waterled, tempin, tempout);

input [3:0] mq7in,waterLevel;
output reg [6:0] leds2;
output reg [6:0] leds;
input tempin;
output reg mqled, waterled;
output reg tempout;

always@(*)
begin

	if(mq7in >= 1) mqled=1;
	else mqled=0;
	
	if(waterLevel > 5) waterled=1;
	else waterled=0;
	tempout= tempin;
	
	case(waterLevel)
		4'b0000: leds = 7'b0000001; // 0
        4'b0001: leds = 7'b1001111; // 1
        4'b0010: leds = 7'b0010010; // 2
        4'b0011: leds = 7'b0000110; // 3
        4'b0100: leds = 7'b1001100; // 4
        4'b0101: leds = 7'b0100100; // 5
        4'b0110: leds = 7'b0100000; // 6
        4'b0111: leds = 7'b0001111; // 7
        4'b1000: leds = 7'b0000000; // 8
        4'b1001: leds = 7'b0000100; // 9
        default: leds = 7'b0000001; // display 0
	endcase
	case(mq7in)
		4'b0000: leds2 = 7'b0000001; // 0
        4'b0001: leds2 = 7'b1001111; // 1
        4'b0010: leds2 = 7'b0010010; // 2
        4'b0011: leds2 = 7'b0000110; // 3
        4'b0100: leds2 = 7'b1001100; // 4
        4'b0101: leds2 = 7'b0100100; // 5
        4'b0110: leds2 = 7'b0100000; // 6
        4'b0111: leds2 = 7'b0001111; // 7
        4'b1000: leds2 = 7'b0000000; // 8
        4'b1001: leds2 = 7'b0000100; // 9
        default: leds2 = 7'b0000001; // display 0
	endcase
end 



endmodule

