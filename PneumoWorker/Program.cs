using PneumoWorker;

IHost host = Host.CreateDefaultBuilder(args).ConfigureServices(services =>
{
    services.AddHostedService<WorkerService>();
}).UseWindowsService().Build();

await host.RunAsync();