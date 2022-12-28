module lab02_light(
	input [7:0] in,
	input rel,
	output reg [2:0] out,
	output reg d,
	output [7:0] seg
);
  integer i;
  always @(*) begin
		if(in == 0)
			d = 0;
		else
			d = 1;
		if(rel) begin
			out = 0;
			for(i = 0; i<7; i++)
				if (in[7-i] == 1) out = i[2:0];
			end
    else out = 0;
	end
  seg seg0(out, seg);
endmodule

module seg(
	input [2:0] in,
	output [7:0] out
);
  always @(*) begin
		case(in)
			3'd0: out[7:0] = 8'hc0;
			3'd1: out[7:0] = 8'hf9;
			3'd2: out[7:0] = 8'ha4;
			3'd3: out[7:0] = 8'hb0;
			3'd4: out[7:0] = 8'h99;
			3'd5: out[7:0] = 8'h92;
			3'd6: out[7:0] = 8'h82;
			3'd7: out[7:0] = 8'hf8;
		default: out[7:0] = 8'hff;
	endcase
end
endmodule
