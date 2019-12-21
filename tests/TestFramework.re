let projectDir =
  Filename.(
    Sys.executable_name
    |> dirname
    |> dirname
    |> dirname
    |> dirname
    |> dirname
    |> dirname
    |> dirname
  );

include Rely.Make({
  let config =
    Rely.TestFrameworkConfig.initialize({
      snapshotDir:
        Filename.(
          projectDir
          |> (dir => concat(dir, "tests"))
          |> (dir => concat(dir, "__snapshots__"))
        ),
      projectDir,
    });
});
