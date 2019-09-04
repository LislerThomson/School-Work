library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity ltplab10 is
	port
	(


		Button : in std_logic;
		CLK : in std_logic;
		Green : out std_logic;
		Red : out std_logic;
		SevenSeg : out std_logic_vector(0 to 6);
		SevenSeg1 : out std_logic_vector(0 to 6);
		Yellow : out std_logic

	);

end ltplab10;

architecture CrossWalk of ltplab10 is

constant ClockTicks : integer:= 50000000;
constant tenBase : integer:= 10;
signal counter: integer range 0 to ClockTicks-1:=0;
signal onesecond: std_logic:='0';
signal Rled: std_logic:='0';
signal YLed: std_logic:='0';
signal Gled: std_logic:='0';
signal traffic: integer range 0 to 8:=0;
signal seven0:integer range 9 downto 0:=4;
signal seven1:integer range 9 downto 0:=1;
signal pressedButton:std_logic:='0';
signal redwait:std_logic:='0';

begin

delaysec:process(CLK) 
begin
if(rising_edge(CLK)) then 


	if(counter = ClockTicks-1) then 
	counter <= 0;
	else
	counter <= counter + 1;
	end if;

	if(Button='0') then
	pressedButton<='1';
	end if;
	
	if(redwait='1') then
		if(counter=0) then
			
			case seven0 is 
				when 0 => SevenSeg <= "0000001";  
				when 1 => SevenSeg <= "1001111"; 
				when 2 => SevenSeg <= "0010010"; 
				when 3 => SevenSeg <= "0000110"; 
				when 4 => SevenSeg <= "1001100"; 
				when 5 => SevenSeg <= "0100100"; 
				when 6 => SevenSeg <= "0100000"; 
				when 7 => SevenSeg <= "0001111"; 
				when 8 => SevenSeg <= "0000000"; 
				when 9 => SevenSeg <= "0000100"; 
				when others => SevenSeg <= "XXXXXXX"; 
			end case;
			case seven1 is 
				when 0 => SevenSeg1 <= "0000001";  
				when 1 => SevenSeg1 <= "1001111"; 
				when 2 => SevenSeg1 <= "0010010"; 
				when 3 => SevenSeg1 <= "0000110"; 
				when 4 => SevenSeg1 <= "1001100"; 
				when 5 => SevenSeg1 <= "0100100"; 
				when 6 => SevenSeg1 <= "0100000"; 
				when 7 => SevenSeg1 <= "0001111"; 
				when 8 => SevenSeg1 <= "0000000"; 
				when 9 => SevenSeg1 <= "0000100"; 
				when others => SevenSeg1 <= "XXXXXXX"; 
			end case;
			
			if(seven1>0) then		
				if(seven0>0) then
					seven0<=seven0-1;
				else
					seven0<=9;
					seven1<=0;
				end if;
			else
			if(seven0>0) then
				seven0<=seven0-1;
			else
			pressedButton<='0';
			seven0<=4;
			seven1<=1;
			end if;
			end if;
		end if;
	end if;
	
	if(pressedButton='1') then
	
		if(counter=0) then	
			if(traffic=0) then
				Rled<='0';
				YLed<='0';
				Gled<='1';
			elsif(traffic=1) then
				Rled<='0';
				YLed<='0';
				Gled<='1';
			elsif(traffic=2) then
				Rled<='0';
				YLed<='0';
				Gled<='1';
			elsif(traffic=3) then
				Rled<='0';
				YLed<='0';
				Gled<='1';
			elsif (traffic=4) then
				Gled<='0';
				Rled<='0';
				YLed<='1';
			elsif (traffic=5) then
				Gled<='0';
				Rled<='0';
				YLed<='1';
			elsif (traffic=6) then
				Gled<='0';
				Rled<='0';
				YLed<='1';
			elsif (traffic=7) then
				Gled<='0';
				Rled<='0';
				YLed<='1';
			elsif(traffic=8) then
				Gled<='0';
				Rled<='1';
				YLed<='0';
				redwait<='1';
			end if;
			
			if(traffic<8) then
			traffic<=traffic+1;
			end if;
		end if;
		
	else 
	Rled<='0';
	YLed<='0';
	Gled<='1';
	traffic<=0;
	SevenSeg<="1111111";
	SevenSeg1<="1111111";
	redwait<='0';
	end if;
end if;
end process delaysec;

Red<=Rled;
Green<=Gled;
Yellow<=Yled;

end;

