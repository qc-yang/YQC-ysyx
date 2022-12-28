module alu(
	input [3:0] a, b,
	input [2:0] sel,
	output z, o, c, s,
	output reg [3:0] out,
)
  wire [3:0] b1, r;
	wire [3:0] oadd, osub, onot, oand, oor, oxor, ocom, oequ;
	assign {c, r} = a + b1;
	assign 
	always @(*) begin
		case(sel)
			3'b000: out = oadd;
			3'b001: out = osub;
		  3'b010: out = onot;
		  3'b011: out = oand;
		  3'b100: out = oor;
			3'b101: out = oxor;
			3'b110: out = ocom;
			3'b111: out = oequ;
			default: out[3:0] = 4'b0000;
		endcase
	end
		  	
