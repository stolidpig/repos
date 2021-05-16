using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawner : MonoBehaviour
{
    public GameObject[] gameObjects;

    public void spawnNext()
    {
        int i = Random.Range(0,gameObjects.Length);

        Instantiate(gameObjects[i], transform.position, Quaternion.identity);
    }


    // Start is called before the first frame update
    void Start()
    {
        spawnNext();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
