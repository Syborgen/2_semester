unit Praktika3;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type

  TForm1 = class(TForm)
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Button1: TButton;
    Button2: TButton;
    Edit4: TEdit;
    Edit5: TEdit;
    Label4: TLabel;
    Label5: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

  TConus = class
  public
   lr : integer;
   h : integer;
   sv : real;
   function v():real;
   function setlr(llr:integer):boolean;
   function seth(hh:integer):boolean;
  end;

var
  Form1: TForm1;
  conus:Tconus;
implementation

{$R *.dfm}


function tconus.setlr(llr:integer):boolean;
begin
lr:=llr;
result:=true;
end;
function tconus.seth(hh:integer):boolean;
begin
h:=hh;
result:=true;
end;

function Tconus.v():real;
begin
  sv:=3.14*lr*lr*h*(1/3);
  result:=sv;
end;


procedure TForm1.Button1Click(Sender: TObject);
var
i1,i2,i3:integer;
er1,er2,er3:boolean;
begin
i1:=strtointdef(Edit1.text,0);

if (i1<=0) then
  begin
  er1:=true;
  edit1.Clear;
  edit1.text:='??????? ????????????? ?????';
  end
  else begin er1:=false
   end;
 i2:=strtointdef(Edit2.text,0);
if (i2<=0) then
  begin
  er2:=true;
  edit2.Clear;
  edit2.text:='??????? ????????????? ?????';
  end
  else
  er2:=false;
  if(er1=true) or (er2=true) then
  showmessage('?????????? ????? ?????');
  edit4.text:=floattostr(3.14*i1*i1*i2*(1/3));
end;

procedure TForm1.Button2Click(Sender: TObject);
var
s:real;
i1,i2,i3:integer;
er1,er2,er3:boolean;
begin
i1:=strtointdef(Edit1.text,0);
if (i1<=0) then
  begin
  er1:=true;
  edit1.Clear;
  edit1.text:='??????? ????????????? ?????';
  end
  else er1:=false;
  i2:=strtointdef(Edit2.text,0);
if (i2<=0) then
  begin
  er2:=true;
  edit2.Clear;
  edit2.text:='??????? ????????????? ?????';
  end
  else
  er2:=false;
  i3:=strtointdef(Edit3.text,0);
if (i3<=0) then
  begin
  er3:=true;
  edit3.Clear;
  edit3.text:='??????? ????????????? ?????';
  end
  else
  er3:=false;
  if(er1=true) or (er2=true) or (er3=true) then
  showmessage('?????????? ????? ?????');
  edit5.text:=floattostr(3.14*(i1*i1+i1*i3+i3*i3)*i2*(1/3));
end;
end.
