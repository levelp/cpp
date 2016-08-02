@for /d %%i in (*) do @(
  @echo === %%i ===
  @pushd %%i
  @call doc.cmd
  @popd )
