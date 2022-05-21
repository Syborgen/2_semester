program Praktika3v;

uses
  Forms,
  Praktika3v2 in 'Praktika3v2.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
