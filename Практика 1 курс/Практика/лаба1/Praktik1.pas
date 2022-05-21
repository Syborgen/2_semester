unit Praktik1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, StrUtils;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Edit1: TEdit;
    procedure Button1Click(Sender: TObject);

  private
  public
    procedure TFunction(st:string);
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
var
s:string;
begin
s:=Edit1.Text;
TFunction(s);
end;
procedure TForm1.TFunction(st:string);
const
   EnglChars = ['A'..'Z','a'..'z'];
var A : array['A'..'z'] of integer;
 i:integer;
 ch : char;
 res:string;
begin
   for ch:='A' to 'z' do A[ch] := 0;
             for i:=1 to Length(st) do
    if st[i] in EnglChars then
           inc( A[ st[i] ] );
  for ch:='A' to 'z' do  begin
    if A[ch]=1 then
      begin
      insert(ch,st,pos(ch,st));
      end;
   end;//for
  for i:=length(st) downto 1 do
  res:=res+st[i];
  showmessage(res);
end;

end.
