// Code your design here
// Code your design here
module mealy_10000(w, clk, reset, z);
  input w, clk, reset; //inputs to the FSM
  output reg z; //output varibale z, it is declared as reg since we will change this indide the always block for mealy machine
  
  reg [2:0] y, Y; //y is the PS variable and Y is the NS variable
  
  //State encoding: We have followed bianry encoding
  parameter [2:0] A=3'b000,
            B=3'b001,
            C=3'b010,
            D=3'b011
            E=3'b100;
  
  
  //In the following always block we have done nothing but just the coded the 
  //state assignment table
  always @(w, y)
    begin
      case(y)
        A:begin
            if(!w) 
              begin
                Y=A;
                z=0;
              end
            else 
              begin
                Y=B;
                z=0;
              end
          end
        B:begin
            if(!w) 
              begin
                Y=C;
                z=0;
              end
            else 
              begin
                Y=B;
                z=0;
              end
          end
        C:begin
            if(!w) 
              begin
                Y=D;
                z=0;
              end
            else 
              begin
                Y=B;
                z=0;
              end
          end
        D:begin
            if(!w) 
              begin
                Y=E;
                z=0;
              end
            else 
              begin
                Y=B;
                z=1;
              end
          end
        E:begin
            if(!w) 
              begin
                Y=A;
                z=1;
              end
            else 
              begin
                Y=B;
                z=0;
              end
          end
        default: Y=2'bxx;
      endcase
    end
        
  //The following always block is the code for D FlipFlop part of the FSM
  always @(posedge clk, negedge reset)
    begin
      if(!reset) y<=A; //active low reset
      else y<=Y;
    end
        
endmodule


