unit Praktika2;
interface
uses
Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
Dialogs, Grids, StdCtrls;
type
TForm1 = class(TForm)



    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    sg: TStringGrid;
    sg2: TStringGrid;
    sg4: TStringGrid;
    sg3: TStringGrid;
    l1: TLabel;
    l2: TLabel;
    l3: TLabel;
procedure Button4Click(Sender: TObject);
procedure FormCreate(Sender: TObject);
procedure Button2Click(Sender: TObject);
procedure Button3Click(Sender: TObject);
procedure Button1Click(Sender: TObject);
private
{ Private declarations }
public
{ Public declarations }
end;
var
Form1: TForm1;
implementation
{$R *.dfm}
procedure TForm1.Button4Click(Sender: TObject);
begin
close;
end;
procedure TForm1.FormCreate(Sender: TObject);
begin
sg.Cells[0, 0] := '????';
sg.Cells[1, 0] := '???????, ???.??.??.';
sg.Cells[2, 0] := '????????? ???.???.';
sg.Cells[0, 1] := '????? ????? ?????';
sg.Cells[0, 2] := '????????';
sg.Cells[0, 3] := '?????????';
sg.Cells[0, 4] := '????? ?????????';
sg.Cells[0, 5] := '???????? ?????????';
sg.Cells[0, 6] := '????????';
end;
type state=record
allMachine, sanMachine, addEmission, aveEmission : integer;
end;
procedure TForm1.Button2Click(Sender: TObject);
var
fout : TextFile;
struct : state;
i, j : integer;
begin
AssignFile(fout, 'G:\????????\????2\????.txt');
Reset(fout);
for j := 1 to 7 do
begin
readln(fout, struct.allMachine, struct.sanMachine);
sg.Cells[1, j] := inttostr(struct.allMachine);
sg.Cells[2, j] := inttostr(struct.sanMachine);
end;
end;
procedure TForm1.Button3Click(Sender: TObject);
var
i, j : integer;
begin
for i := 1 to 2 do
begin
for j := 1 to 7 do
sg.Cells[i, j] := '';
end;
sg2.Visible := false;
sg3.Visible := false;
sg4.Visible := false;
l1.Visible := false;
l2.Visible := false;
l3.Visible := false;
end;
procedure TForm1.Button1Click(Sender: TObject);
var
i, j, maxMachine, maxnum, currentstr : integer;
begin
with sg2 do
begin
maxMachine:=10000;
sg2.Cells[0, 0] := '????';
sg2.Cells[1, 0] := '???????, ???.??.??.';
sg2.Cells[2, 0] := '????????? ???.???.';
maxnum := 1;
for j := 1 to 6 do
begin
if (maxMachine > strtoint(sg.Cells[1, j])) then
begin
maxMachine := strtoint(sg.Cells[1, j]);
maxnum := j;
end;
end;
sg2.rowcount:=2;
sg2.rows[1]:=sg.rows[maxnum];
Visible := true;
l1.Visible := true;
end;
with sg3 do
begin
RowCount := 1;
sg3.Cells[0, 0] := '????';
sg3.Cells[1, 0] := '???????, ???.??.??.';
sg3.Cells[2, 0] := '????????? ???.???.';
currentstr := 1;
for j := 1 to 7 do
begin
if (strtoint(sg.Cells[2, j]) > 3000) then
begin
RowCount := RowCount + 1;
for i := 0 to 2 do
Cells[i, currentstr] := sg.Cells[i, j];
currentstr := currentstr + 1;
end;
end;
Visible := true;
l2.Visible := true;
end;
with sg4 do
begin
RowCount := 1;
sg4.Cells[0, 0] := '????';
sg4.Cells[1, 0] := '???????, ???.??.??.';
sg4.Cells[2, 0] := '????????? ???.???.';
currentstr := 1;
for j := 1 to 5 do
begin
if (strtoint(sg.Cells[1, j]) > 500) then
begin
RowCount := RowCount + 1;
for i := 0 to 4 do
Cells[i, currentstr] := sg.Cells[i, j];
currentstr := currentstr + 1;
end;
end;
Visible := true;
l3.Visible := true;
end;
end;

end.
